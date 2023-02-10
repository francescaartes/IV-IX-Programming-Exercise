import java.util.Random;

public class LotteryNumberGenerator {
   public static void main(String[] args) {
      
      Random randomNumbers = new Random();
      int size = 7;
      int[] lotteryNumbers = new int[size];

      for (int digit = 0; digit < size; digit++) {
         lotteryNumbers[digit] = randomNumbers.nextInt(10);
      }

      System.out.print("Lottery Numbers: ");
      for (int digit = 0; digit < size; digit++) {
         System.out.print(lotteryNumbers[digit] + " ");
      }
   }
}