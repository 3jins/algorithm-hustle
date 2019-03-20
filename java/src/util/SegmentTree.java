package util;

public class SegmentTree {
    private long[] mArr;
    private long[] mSegmentArr;

    public SegmentTree(long[] arr) {
        mArr = arr;
        mSegmentArr = new long[arr.length * 4]; // 4배 외워야 함.
        initTree(0, arr.length - 1, 1); // 인자 외워야 함
    }

    public long initTree(int leftIdx, int rightIdx, int segmentNodeIdx) {
        if (leftIdx == rightIdx) {
            mSegmentArr[segmentNodeIdx] = mArr[leftIdx];
            return mSegmentArr[segmentNodeIdx];
        }
        int midIdx = (leftIdx + rightIdx) / 2;
        mSegmentArr[segmentNodeIdx] = initTree(leftIdx, midIdx, segmentNodeIdx * 2) + initTree(midIdx + 1, rightIdx, segmentNodeIdx * 2 + 1);
        return mSegmentArr[segmentNodeIdx];
    }

    public long getPartialSum(int start, int end) {
        return getPartialSum(start, end, 0, mArr.length - 1, 1);
    }

    private long getPartialSum(int start, int end, int nodeStart, int nodeEnd, int nodeIdx) {
        if (end < nodeStart || start > nodeEnd) return 0;
        if (start <= nodeStart && end >= nodeEnd) return mSegmentArr[nodeIdx];
        int nodeMid = (start + end) / 2;
        return getPartialSum(start, end, nodeStart, nodeMid, nodeIdx * 2) + getPartialSum(start, end, nodeMid + 1, nodeEnd, nodeIdx * 2 + 1);
    }
}
