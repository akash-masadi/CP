import subprocess

def get_wifi_profiles():
    try:
        data = (
            subprocess.check_output(["netsh", "wlan", "show", "profiles"])
            .decode("utf-8")
            .split("\n")
        )
        profiles = [i.split(":")[1][1:-1] for i in data if "All User Profile" in i]
        return profiles
    except subprocess.CalledProcessError as e:
        print(f"Error retrieving profiles: {e}")
        return []

def get_wifi_password(profile):
    try:
        results = (
            subprocess
            .check_output(["netsh", "wlan", "show", "profile", profile, "key=clear"])
            .decode("utf-8")
            .split("\n")
        )
        results = [b.split(":")[1][1:-1] for b in results if "Key Content" in b]
        return results[0] if results else ""
    except subprocess.CalledProcessError as e:
        print(f"Error retrieving password for {profile}: {e}")
        return ""

def main():
    profiles = get_wifi_profiles()
    for profile in profiles:
        password = get_wifi_password(profile)
        print("{:<30}|  {:<}".format(profile, password))

if __name__ == "__main__":
    main()
