package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PurchasingCards11052 {
    private int packSizeToBuy;
    private int[] cardPackPriceArr;

    public PurchasingCards11052() {
        init();
        System.out.println(findHighestHogaengPrice());
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            packSizeToBuy = Integer.parseInt(reader.readLine());
            cardPackPriceArr = new int[packSizeToBuy + 1];
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");
            for (int packSize = 1; packSize <= packSizeToBuy; packSize++) {
                cardPackPriceArr[packSize] = Integer.parseInt(tokenizer.nextToken());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private int findHighestHogaengPrice() {
        int[] recordedPrice = new int[packSizeToBuy + 1];
        recordedPrice[1] = cardPackPriceArr[1];
        for (int packSizeToUpdate = 2; packSizeToUpdate <= packSizeToBuy; packSizeToUpdate++) {
            int maxPrice = cardPackPriceArr[packSizeToUpdate];
            for (int packSize = 1; packSize <= packSizeToUpdate / 2; packSize++) {
                maxPrice = Math.max(
                        recordedPrice[packSize] + recordedPrice[packSizeToUpdate - packSize],
                        maxPrice
                );
            }
            recordedPrice[packSizeToUpdate] = maxPrice;
        }
        return recordedPrice[packSizeToBuy];
    }
}
