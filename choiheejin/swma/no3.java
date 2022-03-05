package choiheejin.swma;

import java.util.*;

public class no3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.nextLine();
        byte[] message = sc.nextLine().getBytes();
        byte[] answer = new byte[message.length];
        for (int i = 0; i < message.length; i++) {
            int c = message[i] - 97;
            System.out.println((c - b) / a);
            answer[i] = (byte) ((c - b) / a + 97);
        }

        System.out.println(new String(answer));
    }
}
