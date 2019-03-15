package util;

import java.util.ArrayList;

public class Sort {
    private ArrayList<Integer> mList;

    public Sort(ArrayList<Integer> list) {
        this.mList = list;
    }

    private void quickSortConcat(int leftIdx, ArrayList<Integer> leftList, ArrayList<Integer> rightList) {
        int leftListSize = leftList.size();
        int rightListSize = rightList.size();
        for (int i = 0; i < leftListSize; i++) {
            mList.set(leftIdx + i, leftList.get(i));
        }
        for(int i = 0; i < rightListSize; i++) {
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
}
