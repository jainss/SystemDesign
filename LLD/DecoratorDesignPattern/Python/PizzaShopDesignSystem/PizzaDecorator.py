from BasePizza import Pizza

class PizzaDecorator(Pizza):
    def __init__(self, pizza: Pizza):
        self.pizza = pizza
 