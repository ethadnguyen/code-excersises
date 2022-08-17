package HelloJava;

public class QuickSort {
    public int partition(int a[], int l, int r) {
        int pivot = a[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (a[j] < pivot) {
                i++;

                // swap
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        // swap a[i+1] and a[r] (or pivot)
        int tmp = a[i + 1];
        a[i + 1] = a[r];
        a[r] = tmp;

        return i + 1;
    }

    public void sort(int a[], int l, int r) {
        if (l < r) {
            int pi = partition(a, l, r);

            sort(a, l, pi - 1);
            sort(a, pi + 1, r);
        }
    }

}
