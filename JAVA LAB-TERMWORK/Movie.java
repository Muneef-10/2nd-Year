// package Class;
// import java.util.*;
// public class Movie
// {
//     private int movieId;
//     private String title;
//     private int duration;
//     private int ticketAvailable;
//     private static int totalTicketSold=0;

//     public Movie(int movieId,String title,int duration,int ticketAvailable)
//     {
//         this.movieId=movieId;
//         this.title=title;
//         this.duration=duration;
//         this.ticketAvailable=ticketAvailable;
//     }
//     public boolean bookTicket(int numberOfTicket)
//     {
//         if(numberOfTicket <= ticketAvailable)
//         {
//             ticketAvailable -= numberOfTicket;
//             totalTicketSold += numberOfTicket;
//             System.out.println(numberOfTicket+" ticket(s) booked successfully for "+ title +".");
//             return true;
//         }
//         else
//         {
//             System.out.println("Not enough tickets available for "+ title +".");
//             return false;
//         }
//     }
    
// }