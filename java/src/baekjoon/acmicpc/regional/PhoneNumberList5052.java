package baekjoon.acmicpc.regional;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

import static java.lang.System.gc;

// 00:02 ~ 00:19
public class PhoneNumberList5052 {
    private int mNumTests;
    private int mNumPhoneNumbers;
    private String[] mPhoneNumberArr;

    public PhoneNumberList5052() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mNumTests = Integer.parseInt(reader.readLine());
            for (int i = 0; i < mNumTests; i++) {
                init(reader);
                gc();
                System.out.println(isArrConsistent() ? "YES" : "NO");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void init(BufferedReader reader) {
        try {
            mNumPhoneNumbers = Integer.parseInt(reader.readLine());
            mPhoneNumberArr = new String[mNumPhoneNumbers];
            for (int i = 0; i < mNumPhoneNumbers; i++) {
                mPhoneNumberArr[i] = reader.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        Arrays.sort(mPhoneNumberArr);
    }

    public boolean isArrConsistent() {
        String lastPhoneNumber = mPhoneNumberArr[0];
        for (int i = 1; i < mNumPhoneNumbers; i++) {
            String curPhoneNumber = mPhoneNumberArr[i];
            if (curPhoneNumber.contains(lastPhoneNumber)) return false;
            lastPhoneNumber = curPhoneNumber;
        }
        return true;
    }
}
