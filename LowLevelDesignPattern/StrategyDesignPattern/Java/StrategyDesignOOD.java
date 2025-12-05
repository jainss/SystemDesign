package StrategyDesignPattern.OODSite;



// startegy
interface behavior{
    void behave();
}
class Normalbehave implements behavior{
    public void behave(){}
}
class Aggressivebehave implements behavior{
    public void behave(){}
}

class Defensivebehave implements behavior{
    public void behave(){}
}

// context
class Robot{
    int name;
    behavior robotBehavior;

    Robot(int name,behavior robotBehavior){
        this.name=name;
        this.robotBehavior=robotBehavior;
    }

    public void setRobotBehavior(behavior robotBehavior) {
        this.robotBehavior = robotBehavior;
    }
    // getters and setters

}
public class StrategyDesign {
    // Client Application
    public static void main(String[] args) {
        Robot r1=new Robot(1,new Normalbehave ());
        Robot r2=new Robot(2,new Aggressivebehave ());
        Robot r3=new Robot(3,new Defensivebehave ());

    }
}
