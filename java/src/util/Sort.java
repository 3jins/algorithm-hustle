package util;

import java.util.ArrayList;

public class Sort {
    private ArrayList<Integer> mList;

    public Sort(ArrayList<Integer> list) {
        this.mList = list;
    }

    /* quick sort */
    private void quickSortConcat(int leftIdx, ArrayList<Integer> leftList, ArrayList<Integer> rightList) {
        int leftListSize = leftList.size();
        int rightListSize = rightList.size();
        for (int i = 0; i < leftListSize; i++) {
            mList.set(leftIdx + i, leftList.get(i));
        }
        for (int i = 0; i < rightListSize; i++) {
            mList.set(leftIdx + leftList.size() + i, rightList.get(i));
        }
    }

    private void quickSort(int leftIdx, int rightIdx) {
        if (rightIdx - leftIdx < 2) return;
        ArrayList<Integer> leftList = new ArrayList<>();
        ArrayList<Integer> rightList = new ArrayList<>();
        int pivot = leftIdx;
        for (int i = leftIdx + 1; i <= rightIdx; i++) {
            if (mList.get(i) < mList.get(pivot)) {
                leftList.add(mList.get(i));
            } else {
                rightList.add(mList.get(i));
            }
        }
        leftList.add(mList.get(pivot));
        quickSortConcat(leftIdx, leftList, rightList);
        quickSort(leftIdx, leftIdx + leftList.size() - 2);
        quickSort(leftIdx + leftList.size(), rightIdx);
    }

    public ArrayList<Integer> quickSort() {
        quickSort(0, mList.size() - 1);
        return mList;
    }

    /* merge sort */
    private void mergeSort(int leftIdx, int rightIdx) {
        if (leftIdx == rightIdx) return;
        int leftIdx1 = leftIdx;
        int rightIdx1 = (leftIdx + rightIdx) / 2;
        int leftIdx2 = (leftIdx + rightIdx) / 2 + 1;
        int rightIdx2 = rightIdx;
        mergeSort(leftIdx1, rightIdx1);
        mergeSort(leftIdx2, rightIdx2);

        ArrayList<Integer> sortedList = new ArrayList<Integer>(rightIdx - leftIdx + 1);
        int i = leftIdx1, j = leftIdx2;
        while (i <= rightIdx1 && j <= rightIdx2) {
            if (mList.get(i) < mList.get(j)) {
                sortedList.add(mList.get(i));
                i++;
            } else {
                sortedList.add(mList.get(j));
                j++;
            }
        }
        while (i <= rightIdx1) {
            sortedList.add(mList.get(i));
            i++;
        }
        while (j <= rightIdx2) {
            sortedList.add(mList.get(j));
            j++;
        }

        for (int k = leftIdx; k <= rightIdx; k++) {
            mList.set(k, sortedList.get(k - leftIdx));
        }
    }

    public ArrayList<Integer> mergeSort() {
        mergeSort(0, mList.size() - 1);
        return mList;
    }
}
