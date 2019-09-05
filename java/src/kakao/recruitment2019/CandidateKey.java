package kakao.recruitment2019;

import java.util.*;

// 18:30 ~ 19:41
public class CandidateKey {
    private List<Integer> archive = new ArrayList<>();
    private String[][] relation;
    private int numKeys;

    public int getNumCandidateKeys(String[][] relation) {
        this.relation = relation;
        numKeys = relation[0].length;
        dfs(1);
        return filterWithMinimality();
    }

    private void dfs(int useKeyIdx) {
        if (useKeyIdx == Math.pow(2, numKeys)) return;
        dfs(useKeyIdx + 1);

        boolean[] useKeyArr = new boolean[numKeys];
        String[] useKeyIdxToArray = Integer.toBinaryString(useKeyIdx).split("");
        int diff = numKeys - useKeyIdxToArray.length;
        for (int key = 0; key < numKeys; key++) {
            if (key < diff) useKeyArr[key] = false;
            else useKeyArr[key] = useKeyIdxToArray[key - diff].equals("1");
        }

        List<String> rowStrList = new ArrayList<>();
        for (String[] row : relation) {
            String rowStr = "";
            for (int key = 0; key < numKeys; key++) {
                if (useKeyArr[key]) {
                    rowStr += (row[key] + " ");
                }
            }
            for (String existingRowStr : rowStrList) {
                if (rowStr.equals(existingRowStr)) return;
            }
            rowStrList.add(rowStr);
        }

        archive.add(useKeyIdx);
    }

    private int filterWithMinimality() {
        int archiveSize = archive.size();
        Map<Integer, Boolean> archiveMap = new HashMap<>();
        for (int useKeyIdx : archive) {
            archiveMap.put(useKeyIdx, true);
        }

        for (int i = 0; i < archiveSize; i++) {
            for (int j = i + 1; j < archiveSize; j++) {
                if ((archive.get(j) & archive.get(i)) == archive.get(j)) {
                    archiveMap.replace(archive.get(i), false);
                }
            }
        }

        int numCandidateKeys = 0;
        for (int useKeyIdx : archive) {
            if (archiveMap.get(useKeyIdx)) numCandidateKeys++;
        }
        return numCandidateKeys;
    }
}
