interface SortStrategy{
    void sort(List<Integer>list);
}
////////////////////////////////////////////////
class InsertionSort implements SortStrategy{
    @java.lang.Override
    public void sort(List<Integer> list) {
        //sort logic
    }
}

class BubbleSort implements SortStrategy{
    @java.lang.Override
    public void sort(List<Integer> list) {
        //sort logic
    }
}

class MergeSort implements SortStrategy{
    @java.lang.Override
    public void sort(List<Integer> list) {
        //sort logic
    }
}
class XYZ implements SortStrategy{
    @java.lang.Override
    public void sort(List<Integer> list) {
        //sort logic
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
class SortContext{
    SortStrategy sortStrategy;
    public SortContext(SortStrategy sortStrategy){
        this.sortStrategy=sortStrategy;
    }

    public void applySort(List<Integer>input){
        sortStrategy.sort(input);
    }
}
////////////////////////////////////////////////////////////////

    /////////Main class
List<Integer>list;
if(getStrategy(list).equals("mergesort")){
    SortContext context=new SortContext(new MergeSort());
    context.applySort(list);
}