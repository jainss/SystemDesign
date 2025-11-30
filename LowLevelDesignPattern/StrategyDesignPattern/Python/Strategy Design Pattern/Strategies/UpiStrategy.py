import uuid
from typing import Dict, Optional
from PaymentStrategy import PaymentStrategy
from exceptions import PaymentError
from Transactions import Transactions

class UpiStrategy(PaymentStrategy):
    def __init__(self, vpa: str):
        self.vpa = vpa

    def _validate(self):
        return "@" in self.vpa and len(self.vpa.split("@")[0]) > 0
    
    def _call_gateway(self, amount, metaData):
        # write the gateway Logic here
        return {'status': "success", "upi_id": "upi-001"}

    def pay(self, amount: float, metaData: Optional[Dict] = None) -> Transactions:
        if amount <=0:
            raise PaymentError("Payment must be greater than zero")
        if not self._validate():
            raise PaymentError("Invalid VPA")
        resp = self._call_gateway(amount, metaData)
        if resp.get("status") != "success":
            raise PaymentError("Paypal failure")
        return Transactions(
            id=str(uuid.uuid4()),
            amount=amount,
            method="UPI",
            status="Success",
            meta = {"card_last4": self.vpa, "upi_id": resp.get("upi_id"), **(metaData or {})}
        )

