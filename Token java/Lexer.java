// Lexer.java // ��ū ����
// Lexical analyzer for Clite, as discusssed in Chapter 3
// Lexical analyzer modified for S

import java.io.*;

public class Lexer {

    private char ch = ' '; 
    private BufferedReader input;
    private String line = "";
    private int col = 1;
    private final String letters = "abcdefghijklmnopqrstuvwxyz"
        + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private final String digits = "0123456789";
    private final String logics = "=" + "!" + ">" + "<";
    private final char eolnCh = '\n';

    public Lexer (String fileName) { // source filename
        try {
            input = new BufferedReader (new FileReader(fileName));
        }
        catch (FileNotFoundException e) {
            System.out.println("File not found: " + fileName);
            System.exit(1);
        }
    }

	public Lexer ( ) { // from standard input 
            input = new BufferedReader (new InputStreamReader(System.in));
			System.out.print(">");
	}

    private char nextChar() { // Return next char
        col++;
        if (col >= line.length()) {
            try {
				System.out.print("    ");
                line = input.readLine( );
                System.out.println(line);
            } catch (IOException e) {
                System.err.println(e);
                System.exit(1);
            } // try
            col = 0;
        } // if col
        return line.charAt(col);
    }
            

    public Token next( ) { // Return next token
        do {
            if (isLetter(ch)) { // ident 
                String spelling = concat(letters + digits);
                System.out.println(spelling);
                return Token.mkIdentTok(spelling);
            } else if (isDigit(ch)) { // int 
                String number = concat(digits);
                return Token.mkIntLiteral(number);
            } else if(isLogical(ch)){
            	String logic = concat(logics);
            	if(logic.equals("!"))
            	{
            		return Token.notTok;
            	}else if(logic.equals("!="))
            	{
            		return Token.notsameTok;
            	}else if(logic.equals("=="))
            	{
            		return Token.sameTok;
            	}else if(logic.equals(">"))
            	{
            		return Token.rightAngleTok;
            	}else if(logic.equals("<"))
            	{
            		return Token.leftAngleTok;
            	}else if(logic.equals(">="))
            	{
            		return Token.rightsameTok;
            	}else if(logic.equals("<="))
            	{
            		return Token.leftsameTok;
            	}
            }else
			switch (ch) {
            case ' ': case '\t': case '\r': case eolnCh:
                ch = nextChar();
                break;
            
            case '/':  // divide 
                ch = nextChar();
                return Token.divideTok;
            
//            case eofCh:  case '.': 
//				return Token.eofTok;
            case '&': ch = nextChar();
                return Token.ampersandTok;
            case '|': ch = nextChar();
                return Token.verti_barTok;
            case '+': ch = nextChar();
                return Token.plusTok;
            case '-': ch = nextChar();
                return Token.minusTok;
            case '*': ch = nextChar();
                return Token.multiplyTok;
            case '(': ch = nextChar();
                return Token.leftParenTok;
            case ')': ch = nextChar();
                return Token.rightParenTok;
            case ';': //ch = nextChar();
                return Token.semicolonTok;
            } // switch
        } while (true);
    } // next


    private boolean isLetter(char c) {
        return (c>='a' && c<='z' || c>='A' && c<='Z');
    }
  
    private boolean isDigit(char c) {
        return (c>='0' && c<='9'); 
    }

    private boolean isLogical (char c) {
    	
    	return (c>='<' && c<= '>' || c == '!');
    }
    
    private String concat(String set) {
        String r = "";
        do {
            r += ch;
            ch = nextChar();
        } while (set.indexOf(ch) >= 0);
        return r;
    }

    public void error (String msg) {
        System.err.print(line);
        System.err.println("Error: column " + col + " " + msg);
        System.exit(1);
    }

    static public void main ( String[] args ) {
        Lexer lexer;
		if (args.length == 0)
            lexer = new Lexer( );
		else
            lexer = new Lexer(args[0]);

        Token tok = lexer.next( );
        while (tok != Token.semicolonTok) {
            System.out.println(tok);
             tok = lexer.next( );
        } 
    } // main
}