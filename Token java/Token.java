// Token.java
// Tokens for Expression Grammar

//import java.lang.Enum;
enum TokenType { //토큰 생성 기준
    Eof, Semicolon, 
    LeftParen, RightParen, 
    Plus, Minus, Multiply,
    Divide, Identifier, IntLiteral,
    Ampersand, Verti_bar, Not, 
    Notsame, Same, LeftAngle ,RightAngle, Leftsame, Rightsame,Assignment, 
    True,False,
}

public class Token {

   public static final Token eofTok = new Token(TokenType.Eof, "<<EOF>>");//eof 토큰 객체
   public static final Token leftParenTok = new Token(TokenType.LeftParen, "("); // ( 토큰
   public static final Token rightParenTok = new Token(TokenType.RightParen, ")"); // ) 토큰 
   public static final Token semicolonTok = new Token(TokenType.Semicolon, ";"); // ; 토큰
   public static final Token plusTok = new Token(TokenType.Plus, "+"); // + 토큰 
   public static final Token minusTok = new Token(TokenType.Minus, "-"); // - 토큰
   public static final Token multiplyTok = new Token(TokenType.Multiply, "*"); // * 토큰
   public static final Token divideTok = new Token(TokenType.Divide, "/"); // /토큰 
   
   public static final Token ampersandTok = new Token(TokenType.Ampersand, "&");
   public static final Token verti_barTok = new Token(TokenType.Verti_bar, "|");
   public static final Token notTok = new Token(TokenType.Not,"!");
  
   public static final Token trueTok =  new Token(TokenType.True, "true");
   public static final Token falseTok = new Token(TokenType.False, "false");
  
   public static final Token assignmentTok = new Token(TokenType.Assignment,"=");
   public static final Token notsameTok = new Token(TokenType.Notsame, "!=");
   public static final Token sameTok = new Token(TokenType.Same,"==");
   public static final Token leftAngleTok = new Token(TokenType.LeftAngle,"<");
   public static final Token rightAngleTok = new Token(TokenType.RightAngle,">");
   public static final Token leftsameTok = new Token(TokenType.Leftsame,"<=");
   public static final Token rightsameTok = new Token(TokenType.Rightsame,">=");



   private TokenType type;
   private String value = "";

   private Token (TokenType t, String v) {
       type = t;
       value = v;
   }

   public TokenType type( ) { return type; }

   public String value( ) { return value; }

   public static Token mkIdentTok (String name) {
	   if(name.equals("true"))
       {
           return Token.trueTok;
       }else if(name.equals("false"))
       {
           return Token.falseTok;       
       }else 
       {
           return new Token(TokenType.Identifier, name);
       }
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