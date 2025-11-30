from abc import ABC, abstractmethod
from typing import Dict, Optional

class PaymentStrategy(ABD):
    @abstractmethod
    def pay(self, amount: float, metaData: Optional[Dict]= None)-> Transaction:
        raise NotImplementedError

