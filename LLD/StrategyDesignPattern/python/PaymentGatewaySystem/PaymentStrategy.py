from abc import ABC, abstractmethod
from typing import Dict, Optional
from Transactions import Transactions

class PaymentStrategy(ABC):
    @abstractmethod
    def pay(self, amount: float, metaData: Optional[Dict]= None)-> Transactions:
        raise NotImplementedError

