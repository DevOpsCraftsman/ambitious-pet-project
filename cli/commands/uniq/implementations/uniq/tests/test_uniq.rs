#[cfg(test)]

mod test {
    use uniq::uniq::uniq;

    #[test]
    fn test_uniq() {
        let s0 = "";
        assert_eq!(uniq(s0), "");
        let s1 = "line";
        assert_eq!(uniq(s1), "line");
        let s2 = "line\nother";
        assert_eq!(uniq(s2), "line\nother");
    }
}
