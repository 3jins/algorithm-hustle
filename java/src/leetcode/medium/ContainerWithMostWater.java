package leetcode.medium;

public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int p1 = 0;
        int p2 = height.length - 1;

        int maxArea = 0;
        while (p2 > p1) {
            maxArea = Math.max(maxArea, (p2 - p1) * Math.min(height[p1], height[p2]));
            if (height[p1] < height[p2]) {
                p1++;
            } else {
                p2--;
            }
        }

        return maxArea;
    }
}
