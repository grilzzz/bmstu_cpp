public class Test {
    public static void main(String[ ] args ) {

        StringBuilder b = new StringBuilder("qwerty");
        SuffixList suff = new SuffixList(b);
        for(String s : suff) System.out.println(s);
        b.insert(1,'x');
        for (String s:suff) System.out.println(s);
    }
}