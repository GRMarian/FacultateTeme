

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.SwingConstants;


public class Tema7 {
	JFrame gui;
	int lini = 6, coloane = 4;
	JButton[] B = new JButton[lini*coloane];
	JTextField txt = new JTextField();
	JTextField txtAns = new JTextField();
	Font font = new Font("NewTimesRoman", Font.ITALIC, 50);
	Color cul1 = new Color(0x01,0x23,0x26);
	Color cul2 = new Color(0x39,0x59,0x34);
	Color cul3 = new Color(0x70,0x8C,0x54);
	Color cul4 = new Color(0x8D,0xA6,0x56);
	Color cul5 = new Color(0xD5,0xD9,0x5F);
	private boolean nextInt = false;
	private boolean canEgal = false;
	private boolean canOperate = true;
	ActionListener listener  = new ActionListener() {
		@Override
		public void actionPerformed(ActionEvent e) {
			JButton Apasat = (JButton) e.getSource();
			String oldTxt;
			switch(Apasat.getName()) {
			case "neg":
				oldTxt = txt.getText();
				if(oldTxt.isEmpty()) {
					txt.setText("-");
					break;
				}
				if(oldTxt.substring(0,1).equals("-")) {
					txt.setText(oldTxt.substring(1));
					break;
				}
				txt.setText("-"+oldTxt);
				break;
			case "calculator":
				try {
					Runtime.getRuntime().exec("calc");
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				break;
			case "operatie":
				if(canOperate==false) {
					break;
				}
				oldTxt = txt.getText();
				oldTxt=oldTxt+" "+Apasat.getText();
				txtAns.setText(oldTxt);
				nextInt = true;
				canEgal = true;
				break;
			case "integer":
				if(nextInt == true) {
					txt.setText("");
				}
				oldTxt = txt.getText();
				oldTxt=oldTxt+Apasat.getText();
				txt.setText(oldTxt);
				nextInt = false;
				break;
			case "calcul":
				switch(Apasat.getText()) {
				case"\u221Ax":
					txtAns.setText("0 \u221A");
					doCalculTxt();
					break;
				case"1/x":
					txtAns.setText("1 /");
					doCalculTxt();
					break;
				case"x^2":
					oldTxt = txt.getText();
					txtAns.setText(oldTxt+" x");
					doCalculTxt();
					break;
				}
				break;
			case "egal":
				if(canEgal==false) {
					break;
				}
				doCalculTxt();
				break;
			case "clear":
				switch(Apasat.getText()) {
				case "C":
					txtAns.setText("");
					txt.setText("");
					break;
				case "CE":
					txt.setText("");
					break;
				case "\\b":
					oldTxt = txt.getText();
					if(oldTxt.isEmpty()) {
						break;
					}
					oldTxt = oldTxt.substring(0, oldTxt.length()-1);
					txt.setText(oldTxt);
					break;
				default:break;
				}
				break;
			default:break;
			}
		}
	};
	Tema7(){
		gui = new JFrame("Calculator");
		gui.setSize(435, 600);
		gui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
		gui.setVisible(true);
		gui.setLayout(null);
		gui.setResizable(false);
		gui.getContentPane().setBackground(cul1);
		addTxtSpace();
		addButtons();
	}
	void addTxtSpace() {
		txt.setEditable(true);
		txt.setBounds(50, 120, 335, 65);
		txt.setHorizontalAlignment(SwingConstants.RIGHT);
		txt.setFont(font);
		txt.setBackground(cul1);
		txt.setForeground(cul5);
		gui.add(txt);
		
		txtAns.setEditable(true);
		txtAns.setBounds(50, 50, 335, 65);
		txtAns.setHorizontalAlignment(SwingConstants.RIGHT);
		txtAns.setFont(font);
		txtAns.setBackground(cul1);
		txtAns.setForeground(cul5);
		gui.add(txtAns);
	}
	void addButtons() {
		int x = 50 , y = 195, w = 80, h = 50;
		int sp= 5 ;
		int x_mem = x;
		
		for(int i = 0; i<lini;i++) {
			for(int j = 0; j<coloane; j++) {
				B[i*coloane+j]=new JButton();
				B[i*coloane+j].addActionListener(listener);
				B[i*coloane+j].setFocusPainted(false);
				gui.add(B[i*coloane+j]);
				B[i*coloane+j].setBounds(x+j*w,y,w,h);
				x=x+sp;
			}
			x= x_mem;
			y=y+h+sp;
		}
	}
	void setupButtons() {
		doOpenCalculator(0,"EZ");
		doClearTxt(1, "CE");
		doClearTxt(2, "C");
		doClearTxt(3, "\\b");
		doComplexCalcul(4, "1/x");
		doComplexCalcul(5, "x^2");
		doComplexCalcul(6, "\u221Ax");
		doOperationButton(7, "/");
		doIntButton(8,"7");
		doIntButton(9,"8");
		doIntButton(10,"9");
		doOperationButton(11,"x");
		doIntButton(12,"4");
		doIntButton(13,"5");
		doIntButton(14,"6");
		doOperationButton(15,"-");
		doIntButton(16,"1");
		doIntButton(17,"2");
		doIntButton(18,"3");
		doOperationButton(19,"+");
		doNegate(20, "+/-");
		doIntButton(21,"0");
		doIntButton(22,".");
		doEgalButton(23,"=");
	}
	void doIntButton(int iter,String number) {
		B[iter].setName("integer");
		B[iter].setText(number);
		B[iter].setBackground(cul3);
		B[iter].setForeground(cul5);
		B[iter].setFont(font);
	}
	void doOperationButton(int iter,String operatie) {
		B[iter].setName("operatie");
		B[iter].setText(operatie);
		B[iter].setBackground(cul2);
		B[iter].setForeground(cul5);
		B[iter].setFont(font);
	}
	void doEgalButton(int iter,String simbol) {
		B[iter].setName("egal");
		B[iter].setText(simbol);
		B[iter].setBackground(cul2);
		B[iter].setForeground(cul5);
		B[iter].setFont(font);
	}
	void doClearTxt(int iter,String simbol) {
		B[iter].setName("clear");
		B[iter].setText(simbol);
		B[iter].setBackground(cul2);
		B[iter].setForeground(cul5);
		B[iter].setFont(new Font("NewTimesRoman", Font.ITALIC, 30));
	}
	void doComplexCalcul(int iter,String simbol) {
		B[iter].setName("calcul");
		B[iter].setText(simbol);
		B[iter].setBackground(cul3);
		B[iter].setForeground(cul5);
		B[iter].setFont(new Font("NewTimesRoman", Font.ITALIC, 30));
	}
	void doOpenCalculator(int iter,String simbol) {
		B[iter].setName("calculator");
		B[iter].setText(simbol);
		B[iter].setBackground(cul2);
		B[iter].setForeground(cul5);
		B[iter].setFont(new Font("NewTimesRoman", Font.ITALIC, 30));
	}
	void doNegate(int iter, String simbol) {
		B[iter].setName("neg");
		B[iter].setText(simbol);
		B[iter].setBackground(cul3);
		B[iter].setForeground(cul5);
		B[iter].setFont(new Font("NewTimesRoman", Font.ITALIC, 30));
	}
	void doCalculTxt() {
		String s1 = txt.getText();
		String s2 = txtAns.getText();
		String operator = s2.substring(s2.length()-1);
		s2=s2.substring(0, s2.length()-2);
		System.out.println(s1);
		System.out.println(s2);
		System.out.println(operator);
		try {
			double drez = 0.0;
			double d1 = Double.parseDouble(s1);
			double d2 = Double.parseDouble(s2);
			
			switch(operator) {
			case"\u221A":
				System.out.println("kjahgkaghkjasfgkahjfg kahgf hafgsdjk");
				drez= Math.sqrt(d1);
				break;
			case "+": 
				drez= d1+d2; 
				break;
			case "-": 
				drez= d2-d1; 
				break;
			case "x": 
				drez= d2*d1; 
				break;
			case "/": 
				if(d1==0.0) {
					throw  new InfinitExeption("Dividing by 0");
				}
				drez= d2/d1; break;
			default:break;
			}

			if(Double.isInfinite(drez)) {
				
				throw  new InfinitExeption("Out of bounds");
			}
			System.out.println(drez);
			String srez = Double.toString(drez);
			txt.setText(srez);
			txtAns.setText("");
		}
		catch(Exception e){
			txtAns.setText("Eroare: "+e.getMessage());
			txt.setText("");
		}
		nextInt = true;
		canEgal = false;
	}

	public static void main(String[] args) {
		Tema7 t = new Tema7();
		t.setupButtons();
	}
}
