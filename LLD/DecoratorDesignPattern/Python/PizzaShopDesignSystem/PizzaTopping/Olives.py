from PizzaDecorator import PizzaDecorator
from BasePizza import Pizza

class Olives(PizzaDecorator):
    def  __init__(self, pizza: Pizza):
        self.pizza = pizza

    def cost(self):
        return f"${self.pizza.cost()} + 10"

    def description(self):
        return f"${self.pizza.description()} + , Olives"
