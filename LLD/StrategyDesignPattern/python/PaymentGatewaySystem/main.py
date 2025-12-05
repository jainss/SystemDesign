from Context import PaymentContext
from Strategies.CreditCardStrategy import CreditCardStrategy
from Strategies.PayPalStrategy import PayPalStrategy
from Strategies.UpiStrategy import UpiStrategy

def main():
    ctx = PaymentContext(CreditCardStrategy("4242 4242 4242 4242", "123", "12/27", "Khushi"))
    tx1 = ctx.pay(100.0, {"order": "ORD1"})
    print("CC:", tx1.to_dict())
    
    ctx.set_strategy(PayPalStrategy("me@example.com"))
    tx2 = ctx.pay(50.0, {"order": "ORD2"})
    print("PayPal:", tx2.to_dict())
    
    ctx.set_strategy(UpiStrategy("me@bank"))
    tx3 = ctx.pay(20.0)
    print("UPI:", tx3.to_dict())
    
main()
    
    

