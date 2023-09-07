#[cfg(test)]
mod test {
    use rust::wc::count_lines;

    #[test]
    fn test_count_lines() {
        let s0 = String::from("");
        assert_eq!(count_lines(&s0), 0);
        let s1 = String::from("this");
        assert_eq!(count_lines(&s1), 1);
        let s3 = String::from("this\nis\nit");
        assert_eq!(count_lines(&s3), 3);
    }
}
