from typing import Optional, Dict
from PaymentStrategy import PaymentStrategy
from PaymentError import PaymentError
from Transaction import Transaction


class PaymentContext:
    def __init__(self, strategy: PaymentStrategy):
        self._strategy = strategy

    def set_strategy(self, strategy: PaymentStrategy) -> None:
        self._strategy = strategy

    def pay(self, amount: float, metadata: Optional[Dict] = None) -> Transaction:
        try:
            return self._strategy.pay(amount, metadata)
        except PaymentError:
            raise
