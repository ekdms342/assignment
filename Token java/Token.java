// Token.java
// Tokens for Expression Grammar

//import java.lang.Enum;
enum TokenType {
     Eof, Semicolon, 
     LeftParen, RightParen, 
     Plus, Minus, Multiply,
     Divide, Identifier, IntLiteral,
}

public class Token {

    public static final Token eofTok = new Token(TokenType.Eof, "<<EOF>>");
    public static final Token leftParenTok = new Token(TokenType.LeftParen, "(");
    public static final Token rightParenTok = new Token(TokenType.RightParen, ")");
	public static final Token semicolonTok = new Token(TokenType.Semicolon, ";");
    public static final Token plusTok = new Token(TokenType.Plus, "+");
    public static final Token minusTok = new Token(TokenType.Minus, "-");
    public static final Token multiplyTok = new Token(TokenType.Multiply, "*");
    public static final Token divideTok = new Token(TokenType.Divide, "/");

    private TokenType type;
    private String value = "";

    private Token (TokenType t, String v) {
        type = t;
        value = v;
    }

    public TokenType type( ) { return type; }

    public String value( ) { return value; }

    public static Token mkIdentTok (String name) {
        return new Token(TokenType.Identifier, name);
    }

    public static Token mkIntLiteral (String name) {
        return new Token(TokenType.IntLiteral, name);
    }

    public String toString ( ) {
        return value;
    } // toString

    public static void main (String[] args) {
        System.out.println(eofTok);
        System.out.println(divideTok);
        System.out.println(multiplyTok);
        System.out.println(rightParenTok);
    }
} // Token