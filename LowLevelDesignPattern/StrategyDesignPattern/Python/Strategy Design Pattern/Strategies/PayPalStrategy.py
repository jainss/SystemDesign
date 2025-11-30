import uuid
from typing import Dict, Optional
from PaymentStrategy import PaymentStrategy
from PaymentError import PaymentError
from Transaction import Transaction

class PayPalStategy(PaymentStrategy):
    def __init__(self, email: str):
        self.email = email

    def _validate(self):
        return "@" in self.email and len(self.email)>3
    
    def _call_gateway(self, amount, metaData):
        # write the gateway Logic here
        return {'status': "success", "pp_tx": "pp-001"}

    def pay(self, amount: float, metaData: Optional[Dict] = None) -> Transaction:
        if amount <=0:
            raise PaymentError("Payment must be greater than zero")
        if not self._validate():
            raise PaymentError("Invalid Paypal email")
        resp = self._call_gateway(amount, metadata)
        if resp.get("status") != "success":
            raise PaymentError("Paypal failure")
        return Transaction(
            id=str(uuid.uuid4()),
            amount=amount,
            method="credit_card",
            status="Success",
            meta = {"card_last4": self.email, "pp_tx": resp.get("pp_tx"), **(metadata or {})}
        )
