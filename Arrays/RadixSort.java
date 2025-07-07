import java.util.Arrays;

public class RadixSort {

    public static void radixSort(int[] arr) {
        int max = getMax(arr); // Step 1: Find max number

        // Step 2: Apply counting sort for every digit (1s, 10s, 100s...)
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSortByDigit(arr, exp);
        }
    }

    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int num : arr)
            if (num > max)
                max = num;
        return max;
    }

    private static void countingSortByDigit(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n]; // Output array
        int[] count = new int[10]; // Count array for digits 0-9

        // Count occurrences of digits
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] to store actual positions
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy sorted array back to original
        System.arraycopy(output, 0, arr, 0, n);
    }

    public static void main(String[] args) {
        int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};
        radixSort(arr);
        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
}
