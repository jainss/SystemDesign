import uuid
from typing import Dict, Optional
from PaymentStrategy import PaymentStrategy
from Transactions import Transactions
from exceptions import PaymentError

class PayPalStrategy(PaymentStrategy):
    def __init__(self, email: str):
        self.email = email

    def _validate(self):
        return "@" in self.email and len(self.email)>3
    
    def _call_gateway(self, amount, metaData):
        # write the gateway Logic here
        return {'status': "success", "pp_tx": "pp-001"}

    def pay(self, amount: float, metaData: Optional[Dict] = None) -> Transactions:
        if amount <=0:
            raise PaymentError("Payment must be greater than zero")
        if not self._validate():
            raise PaymentError("Invalid Paypal email")
        resp = self._call_gateway(amount, metaData)
        if resp.get("status") != "success":
            raise PaymentError("Paypal failure")
        return Transactions(
            id=str(uuid.uuid4()),
            amount=amount,
            method="credit_card",
            status="Success",
            meta = {"card_last4": self.email, "pp_tx": resp.get("pp_tx"), **(metaData or {})}
        )
