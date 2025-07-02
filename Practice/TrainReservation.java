class Berth 
{
    private boolean isAvailable = true;

    public synchronized void bookBerth(String passengerName) {
        if (isAvailable) {
            System.out.println(passengerName + " booked the berth successfully.");
            isAvailable = false;
        } else {
            System.out.println(passengerName + ": Sorry Berth unavailable.");
        }
    }
}

class BookingThread extends Thread {
    private Berth berth;
    private String passengerName;

    BookingThread(Berth berth, String passengerName) {
        this.berth = berth;
        this.passengerName = passengerName;
    }

    public void run() {
        berth.bookBerth(passengerName);
    }
}

public class TrainReservation {
    public static void main(String[] args) {
        Berth berth = new Berth();

        BookingThread passenger1 = new BookingThread(berth, "Passenger A");
        BookingThread passenger2 = new BookingThread(berth, "Passenger B");

        passenger1.start();
        passenger2.start();
    }
}
