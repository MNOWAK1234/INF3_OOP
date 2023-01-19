public class Main {
    public static void main(String[] args) {
        Sequence characters1 = new Characters("WOULD IT EVER WORK");
        Sequence characters2 = new Characters("S EVENTUALLY!");
        Sequence concaternated = new Concatenation(characters1, characters2);
        Sequence lowerCased = new LowerCased(concaternated); 
        Sequence substring = new Substring(lowerCased, 14, 30);
        System.out.println(substring.printedSeq()); // prints "works eventually"
    }
}
