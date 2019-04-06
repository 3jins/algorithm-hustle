package codejam.qr2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.System.gc;

// 14:15 ~ 14:30
public class YouCanGoYourOwnWay {
    private int mDimension;
    private String mFootprintLydia;

    public YouCanGoYourOwnWay() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            int numCases = Integer.parseInt(reader.readLine());
            for (int i = 0; i < numCases; i++) {
                init(reader);
                gc();
                System.out.println("Case #" + (i + 1) + ": " + getMyOwnSolution());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void init(BufferedReader reader) {
        try {
            mDimension = Integer.parseInt(reader.readLine());
            mFootprintLydia = reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getMyOwnSolution() {
        String myOwnSolution = "";
        for (int i = 0; i < 2 * mDimension - 2; i++) {
            if (mFootprintLydia.charAt(i) == 'S') {
                myOwnSolution += "E";
            } else {
                myOwnSolution += "S";
            }
        }
        return myOwnSolution;
    }
}
