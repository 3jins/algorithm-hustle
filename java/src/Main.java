import programmers.level2.MakingBigNumber;

public class Main {

    public static void main(String[] args) {
        String[] param1List = {
                "1924",
                "1231234",
                "4177252841", // 10자리, 4, 1, 2, 2, 제외
                "1911",
        };
        int[] param2List = {
                2,
                3,
                4,
                3,
        };
        String[] expectations = {
                "94",
                "3234",
                "775841",
                "9",
        };

        MakingBigNumber makingBigNumber = new MakingBigNumber();
        int tc = 0;
        while (tc < expectations.length) {
            String result = makingBigNumber.solution(param1List[tc], param2List[tc]);
            if (result.equals(expectations[tc])) System.out.println("pass");
            else System.out.println(result);
            tc++;
        }
    }
}
