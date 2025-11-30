from dataclasses import dataclass
from typing import Dict

@dataclass(frozen=True)
class Transactions:
    id: str
    amount: float
    method: str
    status: str
    meta: Dict

    def to_dict(self) -> Dict:
        return {
            "id": self.id,
            "amount": self.amount,
            "method": self.method,
            "status": self.status,
            "meta": self.meta
        }
