// package Arrays;

// public class CountingSort {
//     public static void countingSort(int[] arr) {
//         int max = arr[0];
//         for (int num : arr) {
//             if (num > max) max = num;
//         }

//         int[] count = new int[max + 1];

//         // Count occurrences
//         for (int num : arr) {
//             count[num]++;
//         }

//         // Cumulative count
//         for (int i = 1; i <= max; i++) {
//             count[i] += count[i - 1];
//         }

//         int[] output = new int[arr.length];

//         // Build output (stable sort, go backwards)
//         for (int i = arr.length - 1; i >= 0; i--) {
//             output[count[arr[i]] - 1] = arr[i];
//             count[arr[i]]--;
//         }

//         // Copy to original array
//         System.arraycopy(output, 0, arr, 0, arr.length);
//     }

//     public static void main(String[] args) {
//         int[] arr = {4, 2, 2, 8, 3, 3, 1};
//         countingSort(arr);
//         for (int num : arr) System.out.print(num + " ");
//     }
// }

import java.util.Arrays;

public class CountingSort{
    public static void countSort(int[] array){
        if(array==null||array.length<=1){
            return;
        }
        int max = array[0];
        for(int num:array){
            if(num>max){
                max=num;
            }
        }
        int[] countinArray=new int[max+1];
        for(int num:array){
            countinArray[num]++;
        }
        int index=0;
        for(int i=0;i<=max;i++){
            while(countinArray[i]>0){
                array[index]=i;
                index++;
                countinArray[i]--;
            }
        }
        
    }
    public static void main(String[] args){
            int[] arr={6,5,3,2,9,8,9,11};
            countSort(arr);
            System.out.println(Arrays.toString(arr));
        }
}








