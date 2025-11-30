from Context import PaymentContext
from CreditCardStrategy import CreditCardStrategy
from DebitCardStrategy import DebitCardStrategy
from PaypalStrategy import PaypalStrategy

def main():
    ctx = PaymentContext(CreditCardStrategy("4242 4242 4242 4242", "123", "12/27", "Khushi"))
    tx1 = ctx.pay(100.0, {"order": "ORD1"})
    print("CC:" tx1)

