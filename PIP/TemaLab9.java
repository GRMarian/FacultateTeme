

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//import java.util.Scanner;

public class TemaLab9 {

	 static void tema() {
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            int inputChar = reader.read();

            while (inputChar != '\n') {
                char UpChar = Character.toUpperCase((char) inputChar);
                System.out.print(UpChar);
                inputChar = reader.read();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Scanner in = new Scanner(System.in);
        //String inputString = in.nextLine();
        //String outputString = inputString.toUpperCase();
        //System.out.println(outputString);
	    //in.close();
		tema();
	}
}
