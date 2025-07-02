// import java.io.*;
// public class FileHand2 //count
// {
//     public static void main(String[] args)
//     {
//         int ch;
//         boolean prev = true;
//         int char_count=0;    
//         int word_count=0;    
//         int line_count=0;
//         FileInputStream fin = new FileInputStream("MyFile.txt");
//         while((ch = fin.read(null))!=-1)
//         {
//             if(ch!=' ')
//                 ++char_count;
//             if(!prev && ch==' ')
//                 ++word_count;
//             if(ch==' ')
//                 prev=true;
//             else 
//                 prev = false;
//             if(ch=='\n')
//                 ++line_count;
//         }
//         char_count -= line_count*2;
//         word_count +=line_count;
//         System.out.println("No. of chars= "+ char_count);
//         System.out.println("No. of words= "+ word_count);
//         System.out.println("No. of lines= "+ line_count);
//         fin.close();
//     }    
// }
