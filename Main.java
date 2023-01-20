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
        waitStart();
        while (true) {
            readerOfState(forState);
            workWithFrame(forState, snake);
            Thread.sleep(1000);
        }

    }
    public static void waitStart() throws FileNotFoundException, InterruptedException {
        while (true) {
            File state = new File("C:\\Users\\VadimAlg\\Desktop\\Alg_C++\\state.txt");
            Scanner reader = new Scanner(state);
            String start = reader.nextLine();
            if (start.equals("start")) {
                break;
            } else {
                Thread.sleep(100);
            }
            reader.close();
        }
    }

    public static void readerOfState(int[][] forState) throws FileNotFoundException {
        File state = new File("C:\\Users\\VadimAlg\\Desktop\\Alg_C++\\state.txt");
        Scanner reader = new Scanner(state);
        String startEnd = reader.nextLine();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                forState[i][j] = reader.nextInt();
            }
        }
        reader.close();
    }

    public static JFrame makeFrame() {
        JFrame snake = new JFrame("Snake");
        snake.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        snake.setLocationRelativeTo(null);
        snake.setSize(510, 530);
        snake.setVisible(true);
        return snake;
    }

    public static void paint(Graphics g, int y1, int x1, int color) {
        if (color == 0) {
            g.setColor(Color.white);
        } else if (color == 5) {
            g.setColor(Color.black);
        } else if (color == 4) {
            g.setColor(Color.red);
        } else {
            g.setColor(Color.blue);
        }
        g.fillRect(x1 + 10, y1 + 30, 50, 50);
    }

    public static void workWithFrame(int[][] forState, JFrame snake) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                paint(snake.getGraphics(), i * 50, j * 50, forState[i][j]);
            }
        }

    }

}
