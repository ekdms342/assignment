import java.io.*;
public class tokenTest2 
{
	
	static int token;
	static StreamTokenizer tokens;
	
	public static void main(String[] args) throws IOException 
	{
		// TODO Auto-generated method stub
		InputStreamReader reader;
		reader = new InputStreamReader(System.in);
		tokens = new StreamTokenizer(reader);//++,!=,�ν� �Ұ�
		
		parse();
	}//lexer, paser �ٸ�Ŭ������ ����
	private static void getToken() throws IOException//lexer�ش�κ�
	{
		token = tokens.nextToken();
	}
	
	private static void parse() throws IOException//���� paser(����) �ش� �κ� 
	{
		getToken();
		command();
	}

	private static void command() throws IOException
	{
		expr();
		if(token == (int)';')
		{
			System.out.println("Syntax OK");
		}else 
		{
			System.out.println("; is required");
		}
	}
	
	private static void expr() throws IOException
	{
		term();
		while(token == '+')
		{
			getToken();
			term();
		}
	}
	
	private static void term() throws IOException
	{
		factor();
		while(token == '*')
		{
			getToken();
			factor();
		}
	}
	
	private static void factor() throws IOException
	{
		if(token == '(')
		{
			getToken();
			expr();
			if(token == ')')
			{
				getToken();
			}else 
			{
				System.out.println(") is required");
				System.exit(0);
			}
		}else if(tokens.ttype == StreamTokenizer.TT_NUMBER)
		{
			getToken();
		}else 
		{
			System.out.println("( or num is reqired");
			System.exit(0);
		}
	}
}

