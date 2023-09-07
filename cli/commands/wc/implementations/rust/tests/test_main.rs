#[cfg(test)]
mod test {
    use rust::wc::{count_bytes, count_lines, count_words};

    #[test]
    fn test_count_lines() {
        let s0 = String::from("");
        assert_eq!(count_lines(&s0), 0);
        let s1 = String::from("this");
        assert_eq!(count_lines(&s1), 1);
        let s3 = String::from("this\nis\nit");
        assert_eq!(count_lines(&s3), 3);
    }

    #[test]
    fn test_count_words() {
        let s0 = String::from("");
        assert_eq!(count_words(&s0), 0);
        let s1 = String::from("this");
        assert_eq!(count_words(&s1), 1);
        let s3 = String::from("this is it");
        assert_eq!(count_words(&s3), 3);
    }

    #[test]
    fn test_count_bytes() {
        let s0 = String::from("");
        assert_eq!(count_bytes(&s0), 0);
        let s1 = String::from("t");
        assert_eq!(count_bytes(&s1), 1);
        let s4 = String::from("this");
        assert_eq!(count_bytes(&s4), 4);
    }
}
