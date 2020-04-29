// Parser.java
// Recursive descent parser for Expression Grammar

import java.io.*;


public class Parser {
    
    Token token;          // current token from the input stream
    Lexer lexer;
    String funcId = "";
    int check = 0;

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
    
    

    private void expr() throws IOException
    {
        bexp();
        if(token.type() == TokenType.Ampersand || token.type() == TokenType.Verti_bar)
        {
            if(token.type() == TokenType.Ampersand)
            {
                while(token.type() == TokenType.Ampersand) 
                {
                    getToken();
                    bexp();
                }
            }else if(token.type() == TokenType.Verti_bar)
            {
                while(token.type() == TokenType.Verti_bar) 
                {
                    getToken();
                    bexp();
                }
            }
        }else if(token.type() == TokenType.Not)
        {
            getToken();
            expr();
        }else if(token.type() == TokenType.True)
        {
            getToken();
        }else if(token.type() == TokenType.False)
        {
            getToken();
        }
        
    }

    private void bexp() throws IOException
    {
        aexp();
        relop();
        if(check != 0)
        {
            aexp();
        }
    }
    
    private void relop() throws IOException
    {
        if(token.type() == TokenType.Same)
        {
            getToken();
            check +=1;
            
        }else if(token.type() == TokenType.Notsame)
        {
            getToken();
            check +=1;
        }else if(token.type() == TokenType.LeftAngle)
        {
            getToken();
            check +=1;
        }else if(token.type() == TokenType.RightAngle)
        {
            getToken();
            check +=1;
        }else if(token.type() == TokenType.Leftsame)
        {
            getToken();
            check +=1;
        }else if(token.type() == TokenType.Rightsame)
        {
            getToken();
            check +=1;
        }
    }
   
    private void aexp() throws IOException {
        term();
        if(token.type() == TokenType.Plus)
        {
            while(token.type() == TokenType.Plus) 
            {
                getToken();
                term();
            }
        }else if(token.type() == TokenType.Minus)
        {
            while(token.type() == TokenType.Minus) 
            {
			    getToken();
			    term();
	        }
        }
		
	}
	
	private void term() throws IOException {
        factor();
        if(token.type() == TokenType.Multiply)
        {
           while(token.type() == TokenType.Multiply) 
            {
			    getToken();
			    factor();
		    } 
        }else if(token.type() == TokenType. Divide)
        {
            while(token.type() == TokenType.Divide) 
            {
			    getToken();
			    factor();
		    } 
        }
		
	}
	
	private void factor() throws IOException {//- 옵션 붙이기
		if (token.type() == TokenType.LeftParen) {
			getToken();
			aexp();
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
