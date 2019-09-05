package kakao.recruitment2019;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// 15:02 ~ 15:48
public class OpenChattingRoom {
    private enum Message {
        Enter("님이 들어왔습니다."), Leave("님이 나갔습니다.");

        private final String message;

        Message(String message) {
            this.message = message;
        }

        public String getMessage() {
            return message;
        }
    }

    public String[] getFinalMessages(String[] records) {
        List<String> finalMessageList = new ArrayList<>();
        Map<String, String> accountTable = new HashMap<>();

        // Make accountTable
        for (String record : records) {
            String[] recordFrags = record.split(" ");
            String command = recordFrags[0];
            if (command.equals(Message.Leave.toString())) continue;
            String id = recordFrags[1];
            String nickName = recordFrags[2];
            accountTable.put(id, nickName);
        }

        // Make finalMessages
        int recordIdx = 0;
        for (String record : records) {
            String[] recordFrags = record.split(" ");
            String command = recordFrags[0];
            String id = recordFrags[1];
            if (command.equals(Message.Enter.toString())) {
                finalMessageList.add(accountTable.get(id) + Message.Enter.getMessage());
            } else if (command.equals(Message.Leave.toString())) {
                finalMessageList.add(accountTable.get(id) + Message.Leave.getMessage());
            }
            recordIdx++;
        }

        return finalMessageList.toArray(new String[finalMessageList.size()]);
    }
}
