package com.craftinginterpreters.lox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

// We start writing our interpreter as Java class called Lox.
// It has two possible ways of running code: 
// 1) giving it a path to a file
// 2) run it interactively as a prompt where you can enter and execute code,
// one line at a time (REPL).

public class Lox {
  public static void main(String[] args) throws IOExcpetion {
    if (args.length > 1) {
      System.out.println("Usage: jlox [script]");
      System.exit(64);
    } else if (args.length == 1) {
      runFile(args[0]);
    } else {
      runPrompt();
    }
  }
}


private static void runFile(String path) throws IOException {
  byte[] bytes = Files.readAllBytes(Paths.get(path));
  run(new String(byrtes, Charset.defaultCharset()));
}

private static void runPrompt() throws IOException {
  InputStreamReader input = new InputStreamReader(System.in);
  BufferedReader reader = new BufferedReader(input);

  for (;;){
    System.out.print("> ");
    String line = reader.readLine();
    if (line == null) break;
    run(line);
  }

}

private static void run(string source) {
   Scanner scanner = new Scanner(source);
   List<Token> tokens = scanner.scanTokens();

   for (Token token : tokens) {
    System.out.println(token);
   }
}


