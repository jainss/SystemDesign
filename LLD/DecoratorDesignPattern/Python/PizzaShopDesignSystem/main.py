from PizzaTypes.Margherita import Margherita
from PizzaTopping.Cheese import Cheese
from PizzaTopping.Olives import Olives
from PizzaTopping.Jalapeno import Jalapeno


def main():
    pizza = Margherita()
    pizza = Cheese(pizza)
    pizza = Olives(pizza)
    pizza = Jalapeno(pizza)
    
    print(pizza.description())
    print("Total Cost:", pizza.cost())
