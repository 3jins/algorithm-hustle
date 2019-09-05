package kakao.recruitment2019;

import java.util.*;

// 16:14 ~ 17:35
public class FailureRate {
    private int MAX_USERS = 200000;

    private List sortMapByValue(Map map, boolean valueDesc, boolean keyDesc) {
        List<String> keyList = new ArrayList<>();
        keyList.addAll(map.keySet());

        Collections.sort(keyList, new Comparator<Object>() {
            @Override
            public int compare(Object key1, Object key2) {
                Object value1 = map.get(key1);
                Object value2 = map.get(key2);

                int valueComparison = (valueDesc ? 1 : -1) * ((Comparable) value2).compareTo(value1);
                if (valueComparison == 0) {
                    return (keyDesc ? 1 : -1) * ((Comparable) key2).compareTo(key1);
                } else {
                    return valueComparison;
                }
            }
        });
        return keyList;
    }

    public int[] getStagesArrangedByFailureRate(int numStage, int[] userStageStates) {
        int[] reached = new int[numStage + 3];
        int[] cleared = new int[numStage + 3];
        // unreached[n] = reached[n] - cleared[n];
        Map<Integer, Double> failureRateMap = new HashMap<>();

        int numUser = userStageStates.length;
        for (int stage = numStage + 1; stage > 0; stage--) {
            cleared[stage] = reached[stage + 1];
            reached[stage] = reached[stage + 1];
            for (int user = 0; user < numUser; user++) {
                if (userStageStates[user] == stage) reached[stage] += 1;
            }
        }
        for (int stage = 1; stage <= numStage; stage++) {
            if (reached[stage] == 0) {
                failureRateMap.put(stage, 0.0);
            } else {
                failureRateMap.put(stage, (reached[stage] - cleared[stage]) / (double) reached[stage]);
            }
        }

        List<Integer> stageListArrangedByFailureRate = sortMapByValue(failureRateMap, true, false);

        return stageListArrangedByFailureRate
                .stream().mapToInt(i->i).toArray();
    }
}
