from typing import Optional, Dict
from PaymentStrategy import PaymentStrategy
from exceptions import PaymentError
from Transactions import Transactions


class PaymentContext:
    def __init__(self, strategy: PaymentStrategy):
        self._strategy = strategy

    def set_strategy(self, strategy: PaymentStrategy) -> None:
        self._strategy = strategy

    def pay(self, amount: float, metadata: Optional[Dict] = None) -> Transactions:
        try:
            return self._strategy.pay(amount, metadata)
        except PaymentError:
            raise
