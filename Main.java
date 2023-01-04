import javax.swing.*;
import java.awt.*;
import java.lang.Object;
import java.awt.desktop.SystemSleepEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.lang.Thread;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, InterruptedException {
        int[][] forState = new int[10][10];
        JFrame snake = makeFrame();
        Thread.sleep(1000);
        while (true) {
            readerOfState(forState);
            clearScreen();
            printState(forState);
            workWithFrame(forState, snake);
            Thread.sleep(1000);
        }

    }

    public static void readerOfState(int[][] forState) throws FileNotFoundException {
        File state = new File("C:\\Users\\VadimAlg\\Desktop\\Alg_C++\\state.txt");
        Scanner reader = new Scanner(state);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                forState[i][j] = reader.nextInt();
            }
        }
        reader.close();
    }

    public static void clearScreen() {
        for (int i = 0; i < 10; ++i) {
            System.out.println("\n\n\n\n\n\n\n\n\n\n");
        }
    }

    public static void printState(int[][] forState) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                System.out.print(forState[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
    }

    public static JFrame makeFrame() {
        JFrame snake = new JFrame("Snake");
        snake.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        snake.setLocationRelativeTo(null);
        snake.setSize(550, 550);

        snake.setVisible(true);
        return snake;
    }

            public static void workWithFrame(int[][] forState, JFrame snake) {
            Graphics g = null;
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (forState[i][j] == 5) {
                        //snake.(j * 50, i * 50, j * 50 + 50, i * 50 + 50);
                    }
                }
            }
    }
}