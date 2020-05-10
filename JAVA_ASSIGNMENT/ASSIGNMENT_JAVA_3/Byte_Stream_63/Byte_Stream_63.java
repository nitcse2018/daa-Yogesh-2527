import java.io.*;

public class Byte_Stream_63 { 

	public static void main(String[] args) throws IOException{
       FileReader file_r = null;
       FileWriter file_w = null;
	String inadd = "D:\\JAVA_ASSIGNMENT_3\\input_file_63.txt"; 
	String outadd = "output_bytestream_63.txt"; 
       try {
    	 	file_r = new FileReader(inadd);
		file_w = new FileWriter(outadd);
   		   int temp; 
           while ((temp = file_r.read()) != -1) 
               file_w.write((byte)temp);      
          System.out.println("READ AND WRITE COMPLETED SUCCESSFULLY!");
       } 
   	catch(Exception e)  // ERROR
   	{
   		System.out.println("ERROR!! FILE DOESN'T EXIST...");
   	}
       finally 
       { 
           if (file_r != null) 
               file_r.close();             
           if (file_w != null)             
               file_w.close();             
       } 
       }
       
	}
