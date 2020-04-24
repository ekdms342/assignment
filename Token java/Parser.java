// Parser.java
// Recursive descent parser for Expression Grammar

import java.io.*;


public class Parser {
    
    Token token;          // current token from the input stream
    Lexer lexer;
    String funcId = "";

    public Parser(Lexer ts) throws IOException { // Open the Clite source program
        lexer = ts;				// as a token stream, and
        token = lexer.next(); // retrieve its first Token
    }
  
	private void getToken() throws IOException {
		token = lexer.next();
	}
	
	private void parse() throws IOException {
		command();
	}

	private void command() throws IOException {
		expr();
		if(token.type() == TokenType.Semicolon)
			System.out.println("Syntax OK");
		else
			System.out.println(";is required");
	}
	
	private void expr() throws IOException {
		term();
		while(token.type() == TokenType.Plus) {
			getToken();
			term();
		}
	}
	
	private void term() throws IOException {
		factor();
		while(token.type() == TokenType.Multiply) {
			getToken();
			factor();
		}
	}
	
	private void factor() throws IOException {
		if (token.type() == TokenType.LeftParen) {
			getToken();
			expr();
			if(token.type() == TokenType.RightParen) getToken();
			else {
				System.out.println(")is required");
				System.exit(0);
			}
		}
		else if (token.type() == TokenType.IntLiteral) {
			getToken();		
		} 
		else if (token.type() == TokenType.Identifier) {
			getToken();		
		} 
		else {
			System.out.println("( or num is required");
			System.exit(0);
		}
	}
    
    public static void main(String args[]) throws IOException {
		Parser parser;

		if (args.length == 0) {
            System.out.println("Begin parsing... ");
		    parser  = new Parser(new Lexer());
		    parser.parse();
		}
    	else {
			System.out.println("Begin parsing... " + args[0]);
			parser  = new Parser(new Lexer(args[0]));
		    parser.parse();
	    }
    } //main

} // Parser
