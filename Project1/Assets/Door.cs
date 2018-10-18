using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Door : MonoBehaviour {

    private bool open;
    private AudioSource source;
    public AudioClip shootSound;

    // Use this for initialization
    void Start () {
        open = false;
        source = GameObject.FindGameObjectWithTag("audio").GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        if (open == true && transform.position.y > -10)
        {
            Vector3 newPos = new Vector3(transform.position.x, Mathf.Max(-10, transform.position.y - 0.95f * Time.deltaTime), transform.position.z);
            transform.position = newPos;
                

        }
        if (open == false && transform.position.y < 0)
        {
            Vector3 newPos = new Vector3(transform.position.x, Mathf.Min(0, transform.position.y + 2 * Time.deltaTime), transform.position.z);
            transform.position = newPos;
        }
    }

    public void OpenDoor()
    {
        open = true;
        source.PlayOneShot(shootSound, 1f);
    }

    public void CloseDoor()
    {
        open = false;
        source.PlayOneShot(shootSound, 1f);
    }
}
