package Arrays;

public class LowestElement {
    public static void main(String[] args) {
        int[] array = {7,5,6,2,9,4,1};
        int minValue = array[0];

        for(int i=0; i<=array.length; i++){
            if(i<minValue){
                minValue=i;
            }
        }
        System.out.println("Lowest value of this array is" + minValue);
    }
}
