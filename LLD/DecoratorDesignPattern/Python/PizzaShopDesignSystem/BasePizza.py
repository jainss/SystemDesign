from abc import ABC, abstractmethod

class Pizza(ABC):
    @abstractmethod
    def cost(self):
        pass
    
    @abstractmethod
    def description(self):
        pass
