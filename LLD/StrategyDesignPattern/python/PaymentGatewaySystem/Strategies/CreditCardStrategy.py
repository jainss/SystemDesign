import uuid
from typing import Dict, Optional
from PaymentStrategy import PaymentStrategy
from Transactions import Transactions
from exceptions import PaymentError

class CreditCardStrategy(PaymentStrategy):
    def __init__(self, card_number: str, cvv: str, expiry:str, name:str):
        self.card_number = card_number.replace(" ","")
        self.cvv= cvv
        self.expiry= expiry
        self.name= name

    def _validate(self):
        return len(self.card_number) in (15,16) and len(self.cvv) in (3,4)
    
    def _call_gateway(self, amount, metaData):
        # write the gateway Logic here
        return {'status': "success", "proc_id": "cc=001"}

    def pay(self, amount: float, metaData: Optional[Dict] = None) -> Transactions:
        if amount <=0:
            raise PaymentError("Payment must be greater than zero")
        if not self._validate():
            raise PaymentError("Invalid credit card data")
        resp = self._call_gateway(amount, metaData)
        if resp.get("status") != "success":
            raise PaymentError("Gateway failure")
        return Transactions(
            id=str(uuid.uuid4()),
            amount=amount,
            method="credit_card",
            status="success",
            meta = {"card_last4": self.card_number[-4:], "proc_id": resp.get("proc_id"), **(metaData or {})}
        )
