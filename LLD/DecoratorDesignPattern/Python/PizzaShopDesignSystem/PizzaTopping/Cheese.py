from BasePizza import Pizza
from PizzaDecorator import PizzaDecorator

class Cheese(PizzaDecorator):
    def  __init__(self, pizza: Pizza):
        self.pizza = pizza

    def cost(self):
        return f"${self.pizza.cost()} + 20"

    def description(self):
        return f"${self.pizza.description()} + , Cheese"
