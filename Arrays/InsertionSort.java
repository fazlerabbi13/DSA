package Arrays;

public class InsertionSort {
    public static void main(String[] args) {
        int[] Array = {65, 31, 28, 13, 24, 17, 95, 5};

        int n = Array.length;
        for (int i = 1; i < n; i++) {
            int insertIndex = i;
            int currentValue = Array[i];
            int j = i - 1;

            while (j >= 0 && Array[j] > currentValue) {
                Array[j + 1] = Array[j];
                insertIndex = j;
                j--;
            }
            Array[insertIndex] = currentValue;
        }

        System.out.print("Sorted array: ");
        for (int value : Array) {
            System.out.print(value + " ");
        }
    }
}
